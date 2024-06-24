# Simple BE FE

This is a simple project to demonstrate how to create a simple backend and frontend.

## 1. Backend

### 1.1. Initialize the project

#### 1.1.1. Create a new folder 
```bash
cd backend
yarn init -y
yarn add express axios dotenv cors body-parser
```

#### 1.1.2. Add scripts into `package.json`

```json
// ./backend/package.json
// between "license" and "dependencies"

"type": "module",
"scripts": {
  "start": "node index.js",
  "dev": "nodemon index.js"
}
```

#### 1.1.3. Create a new file `index.js`

```javascript
// ./backend/index.js
import bodyParser from "body-parser";
import cors from "cors";
import dotenv from "dotenv";
import express from "express";
import mongoose from "mongoose";

dotenv.config();

const app = express();
app.use(bodyParser.json());
app.use(cors());

// Hello world of API

app.get("/", (_, res) => { 
  return res.send({ message: "Hello World!" });
});

const port = process.env.PORT || 8000;
app.listen(port, () =>
  console.log(`Server running on port http://localhost:${port}`),
);
```

#### 1.1.4. Try it! 

```bash
# Run the server
yarn dev

# Test the server
curl http://localhost:8000
```


### 1.2. Add `mongodb`

#### 1.2.1. Install mongoose
```bash
yarn add mongoose
```

#### 1.2.2. Add connection to mongodb in `index.js`

```javascript
// ./backend/index.js

// Add this line at the top
import mongoose from "mongoose";

// Replace the content of `app.listen` part with the following code
mongoose
  .connect(process.env.MONGO_URL, {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  })
  .then(() => { // Success
    app.listen(port, () =>
      console.log(`Server running on port http://localhost:${port}`),
    );
    console.log("Connected to MongoDB");
  })
  .catch((error) => { // Error
    console.log(error.message);
  });
```

## 2. Frontend

### 2.1. Initialize the project

#### 2.1.1. Create a new react app
```bash
yarn create react-app frontend
cd frontend
yarn add axios
```

#### 2.1.2. Try it!
```bash
yarn start
```

