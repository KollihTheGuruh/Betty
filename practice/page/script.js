window.addEventListener("scroll", function() {
    var header = document.querySelector(".sticky-header");
    var scrollY = window.scrollY || window.pageYOffset;
  
    if (scrollY > 100) { // Adjust this value as needed
      header.style.backgroundColor = "#555"; // Change background color when scrolling
    } else {
      header.style.backgroundColor = "#333"; // Reset background color
    }
  });
  