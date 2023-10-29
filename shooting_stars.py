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
meteorite.goto(random.randint(-200, 200), 300)

# Define the tail's colors
fire_colors = ["red", "orange", "yellow"]
smoke_color = "gray"

# Function to create a crater
def create_crater(x, y):
  crater = turtle.Turtle()
  crater.shape("circle")
  crater.shapesize(2, 1)
  crater.color("gray")
  crater.penup()
  crater.speed(0)
  crater.goto(x, y)
  crater.stamp()
  crater.hideturtle()

# Function for the burning meteorite effect
def burning_meteorite():

  # Animate the meteorite falling
  for _ in range(100):
    # Draw a trail behind the meteorite
    meteorite.dot(smoke_color)

    # Make the meteorite smoke
    meteorite.circle(10, smoke_color)

    # Increase the speed of the meteorite as it falls
    meteorite.speed(meteorite.speed() + 1)

    # Move the meteorite forward
    meteorite.goto(meteorite.xcor(), meteorite.ycor() - random.uniform(3, 10))

  # Create a crater where the meteorite hits the ground
  create_crater(meteorite.xcor(), -280)

  # Clear the meteorite
  meteorite.clear()

# Create multiple burning meteorites with a delay between them
for _ in range(5):
  burning_meteorite()
  time.sleep(2)

# Close the turtle graphics window when clicked
screen.exitonclick()
