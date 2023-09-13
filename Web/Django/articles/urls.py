from django.urls import path
from . import views

urlpatterns = [
    path('articles/', views.index),
    path('dinner/', views.dinner),
    path('search/', views.search),
    path('throw/', views.throw),
    path('catch/', views.catch, name='ssafy'),
    # path('hello/<str:name>/', views.greeting),
    path('hello/<name>/', views.greeting),
    path('articles/<int:num>/', views.detail),
]
