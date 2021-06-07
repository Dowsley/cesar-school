FROM node as node
WORKDIR /app
COPY package.json /app/
RUN npm i npm@latest -g
RUN npm install --legacy-peer-deps
COPY ./ /app/
ARG env=prod
RUN npm run build

FROM nginx:1.13
COPY --from=node /app /usr/share/nginx/html
COPY ./nginx-custom.conf /etc/nginx/conf.d/default.conf
