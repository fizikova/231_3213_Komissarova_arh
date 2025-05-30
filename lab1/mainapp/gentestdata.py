import random
from faker import Faker
from .models import AlcoholProduct

fk = Faker()

def gentestdata(n=1000):
    """
    Сгенерировать n записей модели AlcoholProduct.
    """
    categories = [c[0] for c in AlcoholProduct.CATEGORY_CHOICES]
    volumes = [330, 500, 750, 1000, 1500]

    for _ in range(n):
        AlcoholProduct.objects.create(
            name=f"{fk.word().capitalize()} {fk.word().capitalize()}",
            brand=fk.company(),
            category=random.choice(categories),
            volume_ml=random.choice(volumes),
            price=round(random.uniform(50, 5000), 2),
            in_stock=random.choice([True, False]),
            description=fk.sentence(nb_words=12),
            supplier = fk.company()
        )
    print(f" Сгенерировано {n} записей AlcoholProduct")
