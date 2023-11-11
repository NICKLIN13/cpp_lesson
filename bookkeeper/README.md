# Bookkeeper - A simple bookkeeping app  <!-- omit in toc -->

<!-- Reference: https://github.com/ntuee-web-programming/112-1-unit1-todo-list -->

- [1. Frontend Setup](#1-frontend-setup)
    - [1.1. Create a frontend directory and HTML, CSS and JS files](#11-create-a-frontend-directory-and-html-css-and-js-files)
    - [1.2. Import CSS and JS files in `index.html`](#12-import-css-and-js-files-in-indexhtml)
    - [1.3. Run frontend](#13-run-frontend)
- [2. Backend Setup](#2-backend-setup)
    - [2.1. Create a backend directory and initialize a new Node.js project](#21-create-a-backend-directory-and-initialize-a-new-nodejs-project)
    - [2.2. Add `scripts` in `package.json`](#22-add-scripts-in-packagejson)
    - [2.3. Environment variables setting](#23-environment-variables-setting)
    - [2.4. Install dependencies](#24-install-dependencies)
    - [Run the server](#run-the-server)



# 1. Frontend Setup

## 1.1. Create a frontend directory and HTML, CSS and JS files

```bash
mkdir frontend
cd frontend
touch index.html style.css script.js
```

## 1.2. Import CSS and JS files in `index.html`

```html
<!-- index.html -->

<!DOCTYPE html>
<html lang="en">

    <head>
        <link rel="stylesheet" href="style.css" />
        <script defer src="index.js"></script>
        <title>Bookkeeper</title>
    </head>

    <body>
        <h1>Hello world!</h1>
    </body>

</html>
```

## 1.3. Run frontend

Simply click `index.html` in your file explorer to open it in your browser.

<!-- 
## 1.4. Install dependencies

We need to install `axios` to make HTTP requests to the backend server. Add the following line in the `head` tag in `index.html` file. Find the latest version of `axios` [here](https://cdnjs.com/libraries/axios).

```html
<head>
  ...
  <script
    src="https://cdnjs.cloudflare.com/ajax/libs/axios/1.5.0/axios.min.js"
    integrity="sha512-aoTNnqZcT8B4AmeCFmiSnDlc4Nj/KPaZyB5G7JnOnUEkdNpCZs1LCankiYi01sLTyWy+m2P+W4XM+BuQ3Q4/Dg=="
    crossorigin="anonymous"
    referrerpolicy="no-referrer"
  ></script>
  ...
</head>
``` -->


# 2. Backend Setup

## 2.1. Create a backend directory and initialize a new Node.js project

```bash
mkdir backend
cd backend
yarn init -y
```


## 2.2. Add `scripts` in `package.json`

Add the following lines in `package.json` file.

```json
// package.json
{
  ...
  "type": "module",
  "scripts": {
    "start": "node index.js",
    "dev": "nodemon index.js"
  }
}
```


## 2.3. Environment variables setting

Create `.env` and add some lines in it

```bash
cd backend
touch .env
```

```bash
# .env
PORT=8000

# or use `echo` command
echo "PORT=8000" >> .env
```

Remember to add `.env` to `.gitignore` file to protect private information from being exposed.

```bash
cd ..
echo ".env" >> .gitignore
```


##  2.4. Install dependencies

```bash
cd backend
yarn add express cors body-parser uuid dotenv mongoose
```

Remember to add `node_modules` to `.gitignore` file. This is because dependency files are large and not necessary to be uploaded to GitHub. You can always install dependencies by `yarn install` or `npm install` when you clone the project.

```bash
cd ..
echo "node_modules" >> .gitignore
```

## Run the server

```bash
cd backend
yarn dev
```

If successful, you should see the following message in the terminal:

```bash
> Server is running on port http://localhost:8000
```

Next time you can just have to run `yarn dev` to start the server. Step 1-4 are only needed for the first time.