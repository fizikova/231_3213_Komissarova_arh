FROM nginx:alpine

# чтобы подставлять шаблоны
RUN apk add --no-cache gettext

COPY ./templates /etc/nginx/templates

CMD ["sh", "-c", "envsubst '$$BACKEND_HOST' < /etc/nginx/templates/default.conf.template \
    > /etc/nginx/conf.d/default.conf && exec nginx -g 'daemon off;'"]
