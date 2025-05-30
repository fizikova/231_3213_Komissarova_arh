from django.contrib import admin
from .models import AlcoholProduct

@admin.register(AlcoholProduct)
class AlcoholProductAdmin(admin.ModelAdmin):
    list_display   = ('id','name','brand','category','price','in_stock', 'supplier')
    list_filter    = ('category','in_stock', 'supplier')
    search_fields  = ('name','brand', 'supplier')
    
# Register your models here.
