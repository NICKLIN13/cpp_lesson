
const cors = require("cors");
require("dotenv").config();
const express = require("express");
const { connectToMongoDB } = require("./database");

const app = express();
app.use(express.json());
app.use(cors());

const router = require("./routes");

app.use("/api", router)

app.get("/api/hello", async (req, res) => {
    res.status(200).json({"message": "Hello, world!"});
});

const port = process.env.PORT || 5001;

async function startServer() {
    await connectToMongoDB();
    app.listen(port, () => {
        console.log(`Server is listening on http://localhost:${port}`);
    });
}

startServer();
