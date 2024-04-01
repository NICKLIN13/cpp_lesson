const express = require("express");
const router = express.Router();

const { getConnectedClient } = require("./database");
const { ObjectId } = require("mongodb");



// GET STORED TODOS FROM DB 
const getCollection = () => {
    const client = getConnectedClient();
    const collection = client.db("todosdb").collection("todos");
    return collection;
}

// GET  /todos
router.get("/todos", async (req, res) => {
    const collection = getCollection();
    const todos = await collection.find({}).toArray();

    res.status(200).json(todos);
});


// POST  /todos
router.post("/todos", async(req, res) => {
    const collection = getCollection();
    let task = req.body.task;
    let taskDescription = req.body.taskDescription;

    // CHECK IF TODO IS EMPTY
    if (!task) { 
        console.log(req.body)
        return res.status(400).json({ mssg: "error no todo found"});
    }

    // MAKE TASKS INTO STRINGS ANYWAY
    task = (typeof task === "string") ? task : JSON.stringify(task);
    taskDescription = (typeof taskDescription === "string") ? taskDescription : JSON.stringify(taskDescription);

    // INSERT THE TASK INTO THE COLLECTION YOU GOT
    const newTodo = await collection.insertOne({ todo: task, status: false, taskDescription: taskDescription });

    // RESPOND SOME NECESSARY INFORMATION
    res.status(201).json({ todo: task, status: false, _id: newTodo.insertedId });
});


// DELETE  /todos/:id
router.delete("/todos/:id", async(req, res) => {
    const collection = getCollection();
    const _id = new ObjectId(req.params.id);

    const deletedTodo = await collection.deleteOne({_id});


    res.status(200).json(deletedTodo);
});


// PUT  /todos/:id
router.put("/todos/:id", async(req, res) => {
    const collection = getCollection();
    const _id = new ObjectId(req.params.id);
    console.log(req.body)

    const { status } = req.body;

    if (typeof status !== "boolean") {
        return res.status(400).json({ mssg: "invalid status" });
    }

    const updatedTodo = await collection.updateOne({ _id }, { $set: {status: !status} });

    res.status(200).json(updatedTodo);
});

// MAKE THE REPETITION PART OF URLs A ROUTER AND EXPORT IT
module.exports = router;