package backend.backend.Service;

import org.apache.catalina.User;

import java.util.Set;

public interface UserService {

public User addUser(User user);
public User UpdateUser(User user);

public Set<User> getUser();

public User getUserById(Long id);

public String deleteUserById(Long id);

}
