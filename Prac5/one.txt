/*
Daniel Rourke 19386993
 ___ ___ ___   ___ ___ ___   ___ ___ ___ 
| 1 | 1 | 1 | | 1 | 0 | 1 | | 1 | 0 | 1 |
 ___ ___ ___   ___ ___ ___   ___ ___ ___ 
| 1 | 1 | 0 | | 1 | 0 | 0 | | 0 | 0 | 0 |
 ___ ___ ___   ___ ___ ___   ___ ___ ___ 
| 1 | 1 | 1 | | 1 | 0 | 1 | | 1 | 0 | 0 |
 ___ ___ ___   ___ ___ ___   ___ ___ ___ 
| 1 | 1 | 0 | | 1 | 0 | 0 | | 1 | 0 | 0 |
 ___ ___ ___   ___ ___ ___   ___ ___ ___ 
| 1 | 1 | 0 | | 1 | 1 | 0 | | 1 | 0 | 0 |

mkdir -p  a/b/d a/b/e a/b/f a/c/g a/c/h

*/

#include	<stdio.h>
#include	<sys/types.h>
#include    <sys/stat.h>
#include	<dirent.h>

void do_ls(char []);
void show_stat_info(char *, struct stat *);

int main(int ac, char *av[])
{
	if ( ac == 1 )
        	do_ls( "." );
	else
		while ( --ac ){
			printf("%s:\n", *++av );
			do_ls( *av );
		}

        return 1;
}

void do_ls( char dirname[] )
/*
 *	list files in directory called dirname
 */
{
    struct stat info;        /* buffer for file info */
	DIR		*dir_ptr;		/* the directory */
	struct dirent	*direntp;		/* each entry	 */

	if ( ( dir_ptr = opendir( dirname ) ) == NULL )
		fprintf(stderr,"ls1: cannot open %s\n", dirname);
	else
	{
		while ( ( direntp = readdir( dir_ptr ) ) != NULL )
        {
            if( stat(direntp->d_name, &info) != -1 )
                 show_stat_info( direntp->d_name, &info );
            else
                perror(direntp->d_name);  /* report stat() errors  */
        }
		closedir(dir_ptr);
	}
}

void show_stat_info(char *fname, struct stat *buf)
/*
 * displays some info from stat in a name=value format
 */
{
    printf("  inode: %d\n", buf->st_ino);         /* inode number */
    printf("   mode: %o\n", buf->st_mode);         /* type + mode */
    printf("  links: %d\n", buf->st_nlink);        /* # links     */
    printf("   user: %d\n", buf->st_uid);          /* user id     */
    printf("  group: %d\n", buf->st_gid);          /* group id    */
    printf("   size: %d\n", buf->st_size);         /* file size   */
    printf("modtime: %d\n", buf->st_mtime);        /* modified    */
    printf("   name: %s\n", fname );               /* filename    */
}