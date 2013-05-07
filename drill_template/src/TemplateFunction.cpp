/*
 * TemplateFunction.h
 *
 *  Created on: 2013. 5. 7.
 *      Author: alligator410
 */

#ifndef TEMPLATEFUNCTION_H_
#define TEMPLATEFUNCTION_H_

template <typename T>
T const& getMaxVal(T const& a, T const& b){
	return a < b ? b : a;
}


#endif /* TEMPLATEFUNCTION_H_ */
