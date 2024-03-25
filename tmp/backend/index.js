import bodyParser from "body-parser";
import cors from "cors";
import dotenv from "dotenv";
import express from "express";

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