package backend.backend.Controller;


import backend.backend.Service.UserService;
import org.apache.catalina.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/userdetails")
public class UserController {

    @Autowired
    private UserService userService;

//    get all User
    @GetMapping("/")
    public ResponseEntity<?> getallUser()
    {
        return ResponseEntity.ok(this.userService.getUser());
    }
//    get UserbyId
@GetMapping("/{uid}")
    public User getUserById(@PathVariable("uid") Long uid)
    {
        return this.userService.getUserById(uid);
    }

//    delete userbyId
    @DeleteMapping("/{uid}")
    public String deleteUserById(@PathVariable("uid") Long uid)
    {
        return this.userService.deleteUserById(uid);

    }
//    update user

    @PutMapping("/")
    public User updateUser(@RequestBody User user)
    {
return this.userService.UpdateUser(user);
    }
}
