import axios from "axios";


const instance = axios.create({
	baseURL: "http://localhost:5001/api"
});



// EXPORT THESE FUNCTIONS TO ALLOW FRONTEND TO USE
export function getTodos() {
	return instance.get("/todos");
}

export function addTodo(task, taskDescription) {
	return instance.post("/todos", {task, taskDescription});
}

export function deleteTodo(_id) {
	return instance.delete("/todos", {_id})
}