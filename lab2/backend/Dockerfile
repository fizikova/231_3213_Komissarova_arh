FROM python:3.10-slim

ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

WORKDIR /app

COPY requirements.txt .
RUN pip install --upgrade pip \
    && pip install -r requirements.txt

#Копируем весь код проекта
COPY . .

#Сборка статики в STATIC_ROOT
RUN python manage.py collectstatic --noinput

#По умолчанию запускаем Gunicorn на 8000-м порту
CMD ["gunicorn", "lab1.wsgi:application", "--bind", "0.0.0.0:8000"]
