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
// Connect to MongoDB
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