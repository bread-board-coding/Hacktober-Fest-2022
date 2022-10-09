package backend.backend.Service.ServiceImpl;

import backend.backend.Repository.UserRepository;

import backend.backend.Service.UserService;


import org.apache.Entity.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.LinkedHashSet;
import java.util.Set;

@Service
public class UserServiceImpl implements UserService {

    @Autowired
    private UserRepository userRepository;
    @Override
    public User addUser(User user) {
        return this.userRepository.save(user);
    }

    @Override
    public User UpdateUser(User user) {
        return this.userRepository.save(user);
    }

    @Override
    public Set<User> getUser() {
        return new LinkedHashSet<>(this.userRepository.findAll());
    }

    @Override
    public User getUserById(Long id) {
        return this.userRepository.findById(id).get();
    }

    @Override
    public String deleteUserById(Long id) {
this.userRepository.deleteById(id);

return "deleted"+id;
    }
}
