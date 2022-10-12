class CookieStorage {
  create(key, value, time) {
    var expires = "";
    if (time) {
      var date = new Date();
      date.setTime(date.getTime() + time * 24 * 60 * 60 * 1000);
      expires = "; expires=" + date.toUTCString();
    }
    
    document.cookie = key + "=" + value + expires + "; path=/";
  }

  erase(key) {
    this.create(key, "", -1);
  }

  read(key) {
    var keyX = key + "=";
    var ca = document.cookie.split(";");
    for (var i = 0; i < ca.length; i++) {
      var c = ca[i];
      while (c.charAt(0) == " ") c = c.substring(1, c.length);
      if (c.indexOf(keyX) == 0) return c.substring(keyX.length, c.length);
    }

    return null;
  }
}
