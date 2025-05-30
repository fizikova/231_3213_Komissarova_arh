# mainapp/serializers.py
from rest_framework import serializers
from .models import AlcoholProduct

class AlcoholProductSerializer(serializers.ModelSerializer):
    class Meta:
        model = AlcoholProduct
        fields = '__all__'
