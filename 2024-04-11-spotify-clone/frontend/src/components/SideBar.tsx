import HomeOutlinedIcon from '@mui/icons-material/HomeOutlined';
import SearchOutlinedIcon from '@mui/icons-material/SearchOutlined';
import ViewDayOutlinedIcon from '@mui/icons-material/ViewDayOutlined';
import FavoriteOutlinedIcon from '@mui/icons-material/FavoriteOutlined';

const SideBar = () => {
    return (
        <>
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
                            <span>
                                <HomeOutlinedIcon />
                            </span>
                        </a>
                    </li>

                    <li>
                        <a href="#">
                            <span className="fa fa-search"></span>
                            <span>
                                <SearchOutlinedIcon />
                            </span>
                        </a>
                    </li>

                    <li>
                        <a href="#">
                            <span className="fa fas fa-book"></span>
                            <span>
                                <ViewDayOutlinedIcon />
                            </span>
                        </a>
                    </li>
                </ul>
            </div>

            <div className="navigation">
                <ul>
                    <li>
                        <a href="#">
                            <span className="fa fas fa-plus-square"></span>
                            <span>
                                <FavoriteOutlinedIcon />
                            </span>
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
        </>
    )
}

export default SideBar
