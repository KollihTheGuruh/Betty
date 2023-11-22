from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from .models import Laptop, User, Order
# Add any other necessary imports

def home_view(request):
    # Add your view logic here
    return render(request, 'index.html')

def about_us_view(request):
    # Your view logic here
    return render(request, 'about_us.html')

# Login View
def login_view(request):
    if request.method == "POST":
        username = request.POST.get('username')
        password = request.POST.get('password')
        user = authenticate(request, username=username, password=password)
        if user is not None:
            login(request, user)
            # Redirect to a success page.
            return redirect('dashboard')
        else:
            # Return an 'invalid login' error message.
            return render(request, 'login.html', {'error': 'Invalid credentials'})
    else:
        return render(request, 'login.html')

# Dashboard View
def dashboard_view(request):
    if not request.user.is_authenticated:
        return redirect('login')
    # Additional logic based on user type (superuser, client, customer)
    return render(request, 'dashboard.html')

# Product View
def product_view(request):
    laptops = Laptop.objects.all()
    return render(request, 'product_list.html', {'laptops': laptops})

# Compare View
def compare_view(request):
    # This will depend on how you're planning to implement the comparison feature.
    # For instance, you might use query parameters to get the IDs of laptops to compare.
    return render(request, 'compare.html')

# Checkout View
def checkout_view(request):
    if request.method == "POST":
        # Process the checkout form
        # Create an order instance, etc.
        return redirect('payment')
    else:
        # Display checkout form
        return render(request, 'checkout.html')

# Payment View
def payment_view(request):
    if request.method == "POST":
        # Process payment here
        # Integrate with M-Pesa or other payment gateways
        return redirect('success')
    else:
        return render(request, 'payment.html')
