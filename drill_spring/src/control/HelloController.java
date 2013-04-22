package control;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.Controller;

//import javax.servlet.http.HttpServletRequest;

public class HelloController implements Controller{

	@Override
	public ModelAndView handleRequest(HttpServletRequest arg0,
			HttpServletResponse arg1) throws Exception {
		// TODO Auto-generated method stub
		String model = "Springroll";
		String view = "rice";
		ModelAndView mv = new ModelAndView();
		mv.addObject("greet", model);
		
		mv.setViewName(view);
		
		return mv;
	}
	
}
