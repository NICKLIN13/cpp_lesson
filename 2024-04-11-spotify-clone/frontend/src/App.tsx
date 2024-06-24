import './App.css'
import SideBar from "./components/SideBar";
import PlayLists from './components/PlayLists';

function App() {

  return (
    <>
      <body>

        <div className="sidebar">
          <SideBar />
        </div>

        <div className="main-container">
          <div className="topbar">
            <div className="prev-next-buttons">
              <button type="button" className="fa fas fa-chevron-left">Last</button>
              <button type="button" className="fa fas fa-chevron-right">Next</button>
            </div>

            <div className="navbar">
              <ul>
                <li>
                  <a href="#">Premium</a>
                </li>
                <li>
                  <a href="#">Support</a>
                </li>
                <li>
                  <a href="#">Download</a>
                </li>
                <li className="divider">|</li>
                <li>
                  <a href="#">Sign Up</a>
                </li>
              </ul>
              <button type="button">Log In</button>
            </div>
          </div>

          <PlayLists />



          <div className="preview">
            <div className="text">
              <h6>Preview of Spotify</h6>
              <p>Sign up to get unlimited songs and podcasts with occasional ads. No credit card needed.</p>
            </div>
            <div className="button">
              <button type="button">Sign up free</button>
            </div>
          </div>
        </div>

        <script
          src="https://kit.fontawesome.com/23cecef777.js"
          crossorigin="anonymous"
        ></script>
      </body>
    </>
  )
}

export default App
