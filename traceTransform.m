function R=traceTransform( varargin )
%
% Usage:
%
% R=traceTransform( Image , histogram-equalization, functional , prefix )
%
% Input arguments:
% -----------------
% I = input image ( 2-dimensional [gray-scale] or 3-dimensional [color] )
% histogram-equalization: 1=yes 0=no
% functional: 0=radon, 1=T3, 2=T20
% prefix = temporay file prefix
%
% Output argument:
% -----------------
% R = trace image
%
%

t=sum(clock);

warning off;

R=0;
heq = 0;
func = 0;
rgb = 0;
prefix = 'UNK';

nargs = size(varargin,2);


if nargs < 1 || nargs > 4,
    
    fprintf('Invalid number of arguments.  See help\n');
    return;
   
end;

if nargin < 2,  

    I = varargin{1};
    heq = 0;
    func = 0;
    prefix = 'UNK';

elseif nargin < 3,  

    I = varargin{1};
    heq = varargin{2};
    func = 0;
    prefix = 'UNK';
    
elseif nargin < 4,
    
    I = varargin{1};
    heq = varargin{2};
    func = varargin{3};
    prefix = 'UNK';

else,

    I = varargin{1};
    heq = varargin{2};
    func = varargin{3};
    prefix = varargin{4};
    
end;

dim=size(I);

if length(dim) == 3,
    
    rgb = 1;
    
elseif length(dim) <= 1 || length(dim) > 3,
    
    fprintf('Invalid input image ( 2 or 3 dimensions required).  See help.\n');
    return;
    
end;

EXE = './trace.sh ';

HOME = './';

FILE = [prefix '_IM'];

INFILE = [HOME FILE '.jpg'];
OUTFILE = [HOME FILE '.dat'];

imwrite( I , INFILE, 'JPG' );

CMD = [ EXE INFILE ' ' OUTFILE ' ' num2str(func) ' ' num2str(heq) ' ' num2str(rgb) ];

[stat, res]=system( CMD );

if stat ~= 0,
    
    fprintf('Failed to create Trace Image\n');
    R=0;
    
else,
    
    R=load( OUTFILE );
    
end;

delete( INFILE );
delete( OUTFILE );

fprintf('Total time = %.2f (sec)\n', sum(clock) - t );
        
            
    
