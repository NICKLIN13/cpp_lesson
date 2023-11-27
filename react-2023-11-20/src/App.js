import { useState} from "react";
import TodoList from "./TodoList";

function App() {

  let defaultValues = [
    {id: 1, complete: true, name: 'Todo 1'},
    {id: 2, complete: false, name: 'Todo 2'},
    ]

    // newlist = [...defaultValues, {id: 3, complete: false, name: 'Todo 2'},]
  const [todos, setTodos] = useState(defaultValues) // what does useState store?
  return (
    <>
      <TodoList todos = {todos}/>
      <input type="text" />
      <button>Add Todo</button>
      <button>Clear completed Todos</button>
      <div>0 left to do</div>
    </>
  )
}

export default App;
