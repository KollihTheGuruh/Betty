#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <libxml2/libxml/HTMLparser.h>
#include <libxml2/libxml/xpath.h>

#define MAX_GAMES 10
#define MAX_NAME_LEN 20

struct Game {
    char home_team[MAX_NAME_LEN];
    char away_team[MAX_NAME_LEN];
    int home_score;
    int away_score;
}; // Missing semicolon at the end of struct definition

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    xmlDocPtr doc = (xmlDocPtr)userdata;

    htmlParseChunk((htmlParserCtxtPtr)userdata, ptr, nmemb, 0);

    return nmemb;
}

int main() {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return 1;
    }

    CURLcode res;
    xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
    xmlSetDocCompressMode((xmlDocPtr) doc, 0);

    curl_easy_setopt(curl, CURLOPT_URL, "https://odibets.com/league/Results");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, doc);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // Extract game information
    int game_count = 0;
    struct Game games[MAX_GAMES];

    xmlNodePtr node;
    xmlXPathContextPtr xpath_ctx;
    xmlXPathObjectPtr xpath_obj;

    xpath_ctx = xmlXPathNewContext(doc);
    if (!xpath_ctx) {
        fprintf(stderr, "Failed to create XPath context.\n");
        return 1;
    }

    xpath_obj = xmlXPathEvalExpression((const xmlChar*)"//table[@id='tblEvents']//tr", xpath_ctx);
    if (!xpath_obj) {
        fprintf(stderr, "Failed to evaluate XPath expression.\n");
        return 1;
    }

    for (int i = 0; i < xpath_obj->nodesetval->nodeNr; i++) {
        node = xpath_obj->nodesetval->nodeTab[i];

        // Find the columns for the home team, away team, and score
        xmlXPathObjectPtr home_obj = xmlXPathNodeEval(node, (const xmlChar*)"./td[1]/a", xpath_ctx);
        xmlXPathObjectPtr away_obj = xmlXPathNodeEval(node, (const xmlChar*)"./td[3]/a", xpath_ctx);
        xmlXPathObjectPtr score_obj = xmlXPathNodeEval(node, (const xmlChar*)"./td[4]/a", xpath_ctx);

        if (home_obj && away_obj && score_obj) {
            xmlChar *home_name = xmlNodeListGetString(doc, home_obj->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
            xmlChar *away_name = xmlNodeListGetString(doc, away_obj->nodesetval->nodeTab[0]->xmlChildrenNode, 1);
            xmlChar *score_str = xmlNodeListGetString(doc, score_obj->nodesetval->nodeTab[0]->xmlChildrenNode, 1);

            // Convert the score string to integer values
            int home_score = 0, away_score = 0; // Missing semicolon

            sscanf((const char*)score_str, "%d - %d", &home_score, &away_score);

	            // Copy the team names and scores into a new Game struct
        struct Game new_game;
        strncpy(new_game.home_team, (const char*)home_name, MAX_NAME_LEN);
        strncpy(new_game.away_team, (const char*)away_name, MAX_NAME_LEN);
        new_game.home_score = home_score;
        new_game.away_score = away_score;

        // Add the new game to the array of games
        games[game_count++] = new_game;

        xmlFree(home_name);
        xmlFree(away_name);
        xmlFree(score_str);
    }

    xmlXPathFreeObject(home_obj);
    xmlXPathFreeObject(away_obj);
    xmlXPathFreeObject(score_obj);
}

// Print the game information
for (int i = 0; i < game_count; i++) {
    printf("%s %d - %d %s\n", games[i].home_team, games[i].home_score, games[i].away_score, games[i].away_team);
}

// Clean up resources
xmlXPathFreeObject(xpath_obj);
xmlXPathFreeContext(xpath_ctx);
xmlFreeDoc(doc);
curl_easy_cleanup(curl);

return 0;
}
