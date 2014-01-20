/*
 *function: virtual_kernel_address.c
 *description: test kernel virtual address
 *date: 20-Jan-2014
 */


#include <linux/init/h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int __init mmshow_init(void)
{
	printk("mmshow module is working\n");

	pagemem = __get_free_page(GFP_KERNEL);
	if(!pagemem)
		goto gfp_fail;
	printk(KERN_INFO "pagemem = 0x%lx\n",pagemem);

	kmallocmem = kmalloc(100 * sizeof(char),GFP_KERNEL);
	if(!kmallocmem)
		goto kmalloc_fail;
	printk(KERN_INFO "kmallocmem = 0x%p\n",kmallocmem);

	vmallocmem = vmalloc(1000000 * sizeof(char));
	if(!vmallocmem)
		goto vmalloc_fail;
	printk(KERN_INFO "vmallocmem = 0x%p\n",vmallocmem);

	return 0;

gfp_fail:
	free_page(pagemem);
kmalloc_fail:
	kfree(kmallocmem);
vmalloc_fail:
	vfree(vmallocmem);

	return -1;
}

static void __exit mmshow_exit(void)
{
    printk(KERN_ALERT "mm show exit\n");
}

module_init(mmshow_init);
module_exit(mmshow_exit);

/*
[ 5542.073900] mmshow module is working
[ 5542.073904] pagemem = 0xf3211000
[ 5542.073907] kmallocmem = 0xd581e700
[ 5542.073983] vmallocmem = 0xf9251000
 */