import axios from "axios";


const instance = axios.create({
	baseURL: "http://localhost:5001/api"
});

export function getHello() {
	return instance.get("/hello");
}

