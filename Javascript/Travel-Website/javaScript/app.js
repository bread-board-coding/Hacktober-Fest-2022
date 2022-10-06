const navlinks = document.getElementById("nav-links");
const navlink = document.querySelectorAll(".nav-link");
const navbtn = document.getElementById("nav-toggle");

const date = new Date().getFullYear();

document.querySelector(".date").textContent = date;

navbtn.addEventListener("click", () => {
  if (navlinks.classList.contains("show-links")) {
    navlinks.classList.remove("show-links");
  } else {
    navlinks.classList.add("show-links");
  }
});

navlink.forEach((item) => {
  item.addEventListener("click", () => {
    navlinks.classList.remove("show-links");
  });
});

document.querySelector(".slideshow").style.animation = "slideshow 24s infinite";
