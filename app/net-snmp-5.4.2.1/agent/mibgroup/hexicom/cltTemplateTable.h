/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 15999 2007-03-25 22:32:02Z dts12 $
 */
#ifndef CLTTEMPLATETABLE_H
#define CLTTEMPLATETABLE_H

/*
 * function declarations 
 */
void            init_cltTemplateTable(void);
void            initialize_table_cltTemplateTable(void);
Netsnmp_Node_Handler cltTemplateTable_handler;
Netsnmp_First_Data_Point cltTemplateTable_get_first_data_point;
Netsnmp_Next_Data_Point cltTemplateTable_get_next_data_point;

NetsnmpCacheLoad         cltTemplateTable_load;
NetsnmpCacheFree         cltTemplateTable_free;
void cltTemplateTable_commit(unsigned int regNo, void *clientargs);

/*
 * column number definitions for table cltTemplateTable 
 */
#define COLUMN_CLTTEMPLATEINDEX		1
#define COLUMN_CLTTEMPLATENAME		2
#define COLUMN_CLTTEMPLATEDESCRIPTION		3
#define COLUMN_CLTTEMPLATEDEVICEMODELNAME		4
#define COLUMN_CLTTEMPLATEROWSTATUS		5
#define COLUMN_CLTTEMPLATESTORMFILTERENABLE		6
#define COLUMN_CLTTEMPLATEMACLIMITATION		7
#define COLUMN_CLTTEMPLATEETHERNETIFNUMBER		8
#define COLUMN_CLTTEMPLATECABLEUPRATELIMITATION		9
#define COLUMN_CLTTEMPLATECABLEDOWNRATELIMITATION		10
#define COLUMN_CLTTEMPLATECABLEVLANMODE		11
#define COLUMN_CLTTEMPLATECABLEPVID		12
#endif                          /* CLTTEMPLATETABLE_H */
