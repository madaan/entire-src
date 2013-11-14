#sg
def replace_name_node(fpath, destination):
    from lxml import etree
    from os.path import splitext
    from os.path import basename
    import re
    fname = basename(fpath)
    f = open(fpath)
    out = open(destination + fname, 'w')
    for line in f:
        if(re.search('<name>', line) != None):
            out.write('<name>shapes - ' + splitext(fname)[0] + '</name>')
        else:
            out.write(line)

    return 

def copy_files(shape_files_path):

    from os.path import expanduser
    home = expanduser("~")
    destination = home + '/.dia/shapes/'
    for sfp in shape_files_path:
        #shutil.copy(sfp, destination)
        replace_name_node(sfp, destination)


def create_sheet_file(sheet_path, sheet_name, description, shape_names):

    from os.path import splitext
    sheet_file = open(sheet_path, 'w')

    sheet_file.write('<?xml version="1.0" encoding="UTF-8" standalone="no"?>\n')
    sheet_file.write('<sheet xmlns="http://www.lysator.liu.se/~alla/dia/dia-sheet-ns">\n')

    sheet_file.write('<name>%s</name>\n' % splitext(sheet_name)[0])
    sheet_file.write('<description>%s</description>\n<contents>' % description)
    for shape in shape_names:
        sheet_file.write('<object name="shapes - %s">\n' % (splitext(shape)[0]))
        sheet_file.write('<description></description>\n</object>\n')
    
    sheet_file.write('</contents></sheet>\n')
    sheet_file.close()


if __name__ == '__main__':
    import sys
    from os.path import expanduser
    from os import listdir
    from os.path import isfile, join

    if(len(sys.argv) != 3):
        print 'Usage : python shape_installer.py <source_folder> <sheet_name>'
        sys.exit(1)
    #get list of shape files
    source = sys.argv[1]
    sheet_name = sys.argv[2]
    home = expanduser("~")
    sheet_path = home + '/.dia/sheets/' + sheet_name

    shape_file_paths = [ join(source, f) for f in listdir(source) if isfile(join(source, f)) ]
    shape_files = [ f for f in listdir(source) if isfile(join(source, f)) ]
    print shape_files
    #create a sheet
    create_sheet_file(sheet_path, sheet_name, 'trial', shape_files)
    copy_files(shape_file_paths)
