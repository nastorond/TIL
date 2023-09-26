from django.shortcuts import render, redirect
from .models import Restaurant

# Create your views here.
def index(request):
    restaurants = Restaurant.objects.all()
    context = {
        'restaurants': restaurants,
    }
    return render(request, 'restaurants/index.html', context)


def new(request):
    return render(request, 'restaurants/new.html')


def create(request):
    name = request.POST.get('name')
    description = request.POST.get('description')
    address = request.POST.get('address')
    phone_number = request.POST.get('phone_number')

    restaurant = Restaurant(name=name, description=description, address=address, phone_number=phone_number)
    restaurant.save()
    return redirect('restaurants:index')


def detail(request, pk):
    restaurant = Restaurant.objects.get(pk=pk)
    context = {
        'restaurant': restaurant,
    }
    return render(request, 'restaurants/detail.html', context)


def edit(request, pk):
    restaurant = Restaurant.objects.get(pk=pk)
    context = {
        'restaurant': restaurant,
    }
    return render(request, 'restaurants/edit.html', context)


def update(request, pk):
    restaurant = Restaurant.objects.get(pk=pk)
    name = request.POST.get('name')
    description = request.POST.get('description')
    address = request.POST.get('address')
    phone_number = request.POST.get('phone_number')

    restaurant = Restaurant(name=name, description=description, address=address, phone_number=phone_number)
    restaurant.save()
    return redirect('restaurants:detail')