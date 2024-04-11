#include <linux/module.h>
#include <linux/init.h>

/*Meta information (the license you want to use)*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bhavik Programming");
MODULE_DESCRIPTION(" A Hello World Linux Kernel");

/*
 * @brief This function is called when the module is loaded into kernel
 *
 * @description printk() is one of the most widely known functions in the Linux kernel. It's the standard tool we have for printing messages and usually the most basic way of tracing and debugging. If you're familiar with printf(3) you can tell printk() is based on it.
 *
 * KERN ALERT means A problem that requires immediate attention (it will be highlited in RED colour in dmesg kernel space)
*/
static int __init hello_init(void){             /*Constructer*/
	printk(KERN_ALERT "Hello Kernel World\n");
	return 0;
}


/*
 * @brief This funtion is called when the module is removed from the kernel (some kind of clean up in module)
*/
static void __exit hello_exit(void){            /*Destructer*/
	printk(KERN_ALERT "GoodBye, Kernel\n");
}

/*
 * MAIN
 */
module_init(hello_init);
module_exit(hello_exit);


