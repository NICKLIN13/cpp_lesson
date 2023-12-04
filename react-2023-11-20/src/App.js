import { useEffect, useState } from "react";
import TodoList from "./TodoList";

function App() {

  const defaultValues = [
    {id: 1, complete: true, name: 'Todo 1'},
    {id: 2, complete: false, name: 'Todo 2'},
  ]
  

    // newlist = [...defaultValues, {id: 3, complete: false, name: 'Todo 2'},]
  const [todos, setTodos] = useState(defaultValues) // what does useState store?
  console.log('old', todos)
  useEffect(() => {
    if (todos.length >=20) {
      console.log("DO STH!!")
    }
  },[todos])
  
  function handleAddTodo(e) {
    setTodos(
      (todos) => {
        return [
          ...todos,
          {id: 2, complete: false, name: todos.length}
          // TODO: how to use `useState` to make `name` changing on todos?
        ]
      }
    )
  }


  // count = 5
  // queue = [5+1, 5+1, 5+1] //XXX
  // queue = [x+1, x+1, x+1]
  console.log('new', todos)
  return (
    <>
      <TodoList todos = {todos}/>
      <input type="text" />
      <button onClick={handleAddTodo}>Add Todo</button>
      <button>Clear completed Todos</button>
      <div>0 left to do</div>
    </>
  )
}

export default App;
