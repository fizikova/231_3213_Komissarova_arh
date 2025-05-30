from django.shortcuts import render
# mainapp/views.py
from rest_framework import viewsets
from .models import AlcoholProduct
from .serializers import AlcoholProductSerializer

class AlcoholProductViewSet(viewsets.ModelViewSet):
    queryset = AlcoholProduct.objects.all()
    serializer_class = AlcoholProductSerializer

    filterset_fields = ['category', 'in_stock', 'brand']
    search_fields = ['name', 'brand']
    ordering_fields = ['price', 'volume_ml']

# Create your views here.
