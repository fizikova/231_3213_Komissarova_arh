from django.db import models

class AlcoholProduct(models.Model):
    BEER = 'beer'
    WINE = 'wine'
    SPIRIT = 'spirit'
    CATEGORY_CHOICES = [
        (BEER, 'Пиво'),
        (WINE, 'Вино'),
        (SPIRIT, 'Крепкий алкоголь'),
    ]

    name = models.CharField(
        max_length=100,
        verbose_name='Название продукта'
    )
    brand = models.CharField(
        max_length=100,
        verbose_name='Бренд'
    )
    category = models.CharField(
        max_length=10,
        choices=CATEGORY_CHOICES,
        default=BEER,
        verbose_name='Категория'
    )
    volume_ml = models.PositiveIntegerField(
        verbose_name='Объем (мл)'
    )
    price = models.DecimalField(
        max_digits=8,
        decimal_places=2,
        verbose_name='Цена, RUB'
    )
    in_stock = models.BooleanField(
        default=True,
        verbose_name='В наличии'
    )
    description = models.TextField(
        blank=True,
        verbose_name='Описание'
    )
    supplier = models.CharField(
         max_length=100,
         blank=True,
         verbose_name='Поставщик'
    )

    def __str__(self):
        return f"{self.name} ({self.brand})"

