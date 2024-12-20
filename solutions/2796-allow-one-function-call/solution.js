/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    
       
        let result;
        let iscalled=false;

    return function(...args){

        if(!iscalled){
          result=fn(...args);
          iscalled=true;
          return result;
        }

          return undefined;
        
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */

