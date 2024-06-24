// {id: 1, complete: false, name: 'Todo 1'}
export default function Todo( {todo} ) {
  return (
    <div>
      <input type="checkbox" checked={todo.complete}/>
      {todo.name}
    </div>
  )
}