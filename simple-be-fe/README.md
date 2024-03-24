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

### Try it! 

#### Run the server
```bash
yarn dev
```
#### Test the server
```bash
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