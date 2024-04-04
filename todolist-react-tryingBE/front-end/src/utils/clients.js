import axios from "axios";


const instance = axios.create({
	baseURL: "http://localhost:5001/api"
});



// EXPORT THESE FUNCTIONS TO ALLOW FRONTEND TO USE
export function getTodos() {
	return instance.get("/todos");
}

export function addTodo(title, description) {
	return instance.post("/todos", {title: title, description: description});
}

export function deleteTodo(_id) {
	return instance.delete("/todos", {_id})
}

export function editTask(id, taskDescription) {
	// return instance.put(`/todos/${id}`, {taskDescription})
	return
}

export function toggleComplete(id, completed) {
	return instance.put(`/todos/${id}`, {completed: completed})
}