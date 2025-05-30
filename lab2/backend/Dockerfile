# 1) Базовый образ Python 3.10 (slim)
FROM python:3.10-slim

# 2) Отключаем .pyc и буферизацию вывода
ENV PYTHONDONTWRITEBYTECODE=1
ENV PYTHONUNBUFFERED=1

WORKDIR /app

# 3) Сначала ставим зависимости (кешируем слой)
COPY requirements.txt .
RUN pip install --upgrade pip \
    && pip install -r requirements.txt

# 4) Копируем весь код проекта
COPY . .

# 5) Сборка статики в STATIC_ROOT
RUN python manage.py collectstatic --noinput

# 6) По умолчанию запускаем Gunicorn на 8000-м порту
CMD ["gunicorn", "lab1.wsgi:application", "--bind", "0.0.0.0:8000"]
