
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include <linux/fs.h>

/*Meta information (the license you want to use)*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bhavik Programming");
MODULE_DESCRIPTION(" Registration of device number and implement any callback function");

dev_t device_number = MKDEV(150,1);
/*
 * @brief We will assign a major number as a macro and minor number with struct, and 
 * then we will register device number to vfs. (virtual file system)
 *
 * to check which driver is available then use /proc/devices
 *
 * int register_chrdev_region(dev_t first, unsigned int count, char *name); (static allocation)
 * 			     (Major Minor,num of device we req, name of device); 
 *
 * int alloc_chrdev_region(dev_t *dev, Unsigned int Minor, int count, char *name); (dynamic 
 * allocation) Major number will be assigned by kernel itself.
*/
static int __init device_num_init(void)
{
	register_chrdev_region(device_number, 1, "myDeviceDriverNumber");
	printk("Major = %d and Minor = %d \n",MAJOR(device_number),MINOR(device_number));
	printk("Kernel Module insterted successfully....\n");
	return 0;
}


/*
 * @brief This funtion is called when the module is removed from the kernel (some kind of clean up in module)
*/
static void __exit device_num_exit(void)
{
	unregister_chrdev_region(device_number, 1);
	printk("kernel Module removed successfully....\n");
}

/*
 * MAIN
 */
module_init(device_num_init);
module_exit(device_num_exit);
