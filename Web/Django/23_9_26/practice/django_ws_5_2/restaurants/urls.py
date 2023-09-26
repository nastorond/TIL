from django.urls import path, include
from . import views

app_name = 'restaurants'
urlpatterns = [
    path('', views.index, name='index'), 
    path('new/', views.new, name="new"),
    path('create/', views.create, name='create'),
    path('<int:pk>/', views.detail, name='detail'),
    path('<int:pk>/edit/', views.edit, name='name'),
    path('<int:pk>/update/', views.update, name='update')
]