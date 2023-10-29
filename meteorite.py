
import turtle
import random
import time

# Set up the screen
screen = turtle.Screen()
screen.bgcolor("black")
screen.title("Burning Meteorite")
screen.setup(width=800, height=600)

# Configure the turtle representing the meteorite
meteorite = turtle.Turtle()
meteorite.shape("circle")
meteorite.color("orange")
meteorite.penup()
meteorite.speed(0)
meteorite.goto(0, 290)

# Define the tail's colors
fire_colors = ["red", "orange", "yellow"]

# Function for the burning meteorite effect
def burning_meteorite():
    # Create the fire tail
    for _ in range(10):
        meteorite.color(random.choice(fire_colors))
        meteorite.goto(0, 290)
        meteorite.pendown()
        meteorite.goto(random.randint(-10, 10), 260)
        meteorite.penup()
    
    # Simulate the meteorite falling
    for _ in range(30):
        meteorite.color("orange")
        meteorite.goto(random.randint(-10, 10), 260 - random.randint(1, 20))
    
    # Clear the meteorite and tail
    meteorite.clear()

# Create multiple burning meteorites with a delay between them
for _ in range(5):
    burning_meteorite()
    time.sleep(1)

# Close the turtle graphics window when clicked
screen.exitonclick()
