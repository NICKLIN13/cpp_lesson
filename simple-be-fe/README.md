# Simple BE FE

This is a simple project to demonstrate how to create a simple backend and frontend.

## Backend

### Init

```bash
cd backend
yarn init -y
yarn add express axios dotenv cors body-parser
```

### Add scripts into `package.json`

```json
// between "license" and "dependencies"

"type": "module",
"scripts": {
  "start": "node index.js",
  "dev": "nodemon index.js"
}
```