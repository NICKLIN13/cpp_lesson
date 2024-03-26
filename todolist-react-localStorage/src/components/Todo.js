import React from 'react'
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'
import { faPenToSquare} from '@fortawesome/free-solid-svg-icons'
import { faTrash } from '@fortawesome/free-solid-svg-icons'

const Todo = ({task, toggleComplete, deleteTodo, editTodo}) => {
  return (
    <div className='Todo'>

		<details id="" class="todo-item">
			<summary >
				<p onClick={(e) => {e.preventDefault(); toggleComplete(task.id);}} className={`${task.completed ? 'completed': ""}`}>{task.task}</p>

				<div>
					<FontAwesomeIcon icon={faPenToSquare} onClick={() => editTodo(task.id)}/>
					<FontAwesomeIcon icon={faTrash} onClick={() => deleteTodo(task.id)} />
				</div>

			</summary>

			<p class="todo-description">{task.taskDescription}</p>
		</details>
		
    </div>
  )
}

export default Todo
