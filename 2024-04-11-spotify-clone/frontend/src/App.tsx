import './App.css'

function App() {

  return (
    <>
      <body>

        <div className="sidebar">
          <div className="logo">
            <a href="#">
              <img src="https://storage.googleapis.com/pr-newsroom-wp/1/2018/11/Spotify_Logo_CMYK_Green.png" alt="Logo" />
            </a>
          </div>

          <div className="navigation">
            <ul>
              <li>
                <a href="#">
                  <span className="fa fa-home"></span>
                  <span>Home</span>
                </a>
              </li>

              <li>
                <a href="#">
                  <span className="fa fa-search"></span>
                  <span>Search</span>
                </a>
              </li>

              <li>
                <a href="#">
                  <span className="fa fas fa-book"></span>
                  <span>Your Library</span>
                </a>
              </li>
            </ul>
          </div>

          <div className="navigation">
            <ul>
            <li>
                <a href="#">
                  <span className="fa fas fa-plus-square"></span>
                  <span>Nick Playlist</span>
                </a>
              </li>

              <li>
                <a href="#">
                  <span className="fa fas fa-plus-square"></span>
                  <span>Create Playlist</span>
                </a>
              </li>

              <li>
                <a href="#">
                  <span className="fa fas fa-heart"></span>
                  <span>Liked Songs</span>
                </a>
              </li>
            </ul>
          </div>

          <div className="policies">
            <ul>
              <li>
                <a href="#">Cookies</a>
              </li>
              <li>
                <a href="#">Privacy</a>
              </li>
            </ul>
          </div>
        </div>

        <div className="main-container">
          <div className="topbar">
            <div className="prev-next-buttons">
              <button type="button" className="fa fas fa-chevron-left"></button>
              <button type="button" className="fa fas fa-chevron-right"></button>
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

          <div className="spotify-playlists">
            <h2>Spotify Playlists</h2>

            <div className="list">
              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Today's Top Hits</h4>
                <p>Rema & Selena Gomez are on top of the...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>RapCaviar</h4>
                <p>New Music from Lil Baby, Juice WRLD an...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>All out 2010s</h4>
                <p>The biggest spmgs pf tje 2010s. Cover:...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Rock classNameics</h4>
                <p>Rock Legends & epic songs that continue t...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Chill Hits</h4>
                <p>Kick back to the best new and recent chill...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Viva Latino</h4>
                <p>Today's top Latin hits elevando nuestra...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Mega Hit Mix</h4>
                <p>A mega mix of 75 favorites from the last...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>All out 80s</h4>
                <p>The biggest songs of the 1090s.</p>
              </div>
            </div>
          </div>

          <div className="spotify-playlists">
            <h2>Focus</h2>
            <div className="list">
              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Peaceful Piano</h4>
                <p>Relax and indulge with beautiful piano pieces</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Deep Focus</h4>
                <p>Keep calm and focus with ambient and pos...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Instrumental Study</h4>
                <p>Focus with soft study music in the...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>chill lofi study beats</h4>
                <p>The perfect study beats, twenty four...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Coding Mode</h4>
                <p>Dedicated to all the programmers out there.</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Focus Flow</h4>
                <p>Uptempo instrumental hip hop beats.</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Calm Before The Storm</h4>
                <p>Calm before the storm music.</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Beats to think to</h4>
                <p>Focus with deep techno and tech house.</p>
              </div>
            </div>
          </div>

          <div className="spotify-playlists">
            <h2>Mood</h2>
            <div className="list">
              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Mood Booster</h4>
                <p>Get happy with today's dose of feel-good...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Feelin' Good</h4>
                <p>Feel good with this positively timeless...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Dark & Stormy</h4>
                <p>Beautifully dark, dramatic tracks.</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Feel Good Piano</h4>
                <p>Happy vibes for an upbeat morning.</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Feelin' Myself</h4>
                <p>The hip-hop playlist that's a whole mood...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Chill Tracks</h4>
                <p>Softer kinda dance</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>Feel-Good Indie Rock</h4>
                <p>The best indie rock vibes - classNameic and...</p>
              </div>

              <div className="item">
                <img src="https://i.scdn.co/image/ab67616d0000b2733b5e11ca1b063583df9492db" />
                <div className="play">
                  <span className="fa fa-play"></span>
                </div>
                <h4>idk.</h4>
                <p>idk.</p>
              </div>
            </div>

            
          </div>

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
