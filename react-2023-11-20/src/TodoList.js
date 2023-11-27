import Todo from './Todo'

export default function TodoList({ todos }) {
  return (
    todos.map(todo => {
      return <Todo key = {todo} todo = {todo} />
    })
  )
}

/*
newList = list.filter(func)

newList = []
for item in list:
  if func(item):
    newLint.append()

return newList
*/