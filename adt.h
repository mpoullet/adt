/* FILE GENERATED BY ADT, DO NOT EDIT
input =
	INPUT( structural string header, structural body *body, structural string trailer ) ;
body =
	INSTANCE list(structural def *def) ==>
	BODY( structural def *def, structural body *next ) ;
def =
	DEF( structural string comment, structural ident *ident, structural product *product, structural adt *adt ) ;
adt =
	ADT( structural sum *sum, structural string class, structural product *parameters ) ;
sum =
	INSTANCE list(structural summand *summand) ==>
	SUM( structural summand *summand, structural sum *next ) ;
summand =
	SUMMAND( structural string comment, structural ident *ident, structural product *product ) ;
product =
	INSTANCE list(structural factor *factor) ==>
	PRODUCT( structural factor *factor, structural product *next ) ;
factor =
	FACTOR( structural string comment, structural int visibility, structural ident *type, structural string star, structural ident *field ) ;
ident =
	IDENT( structural string ident )

*/

#ifndef _adt_
#define _adt_

extern void fatal( int dummy, char *s, ... ) ;
#define	check_ptr( source, proc )\
	if( source == NULL ) { \
		fatal( 0, "%s( NULL )", proc ) ;\
	}

#define	check_tag( source, constr, proc )\
	check_ptr( source, proc )\
	if( source->tag != constr ) {\
		__adterr__( source, source->tag, constr, proc ) ;\
	}

#define input_BIND 0
typedef	enum { INPUT=1 } input_tag ;
#define body_BIND 2
typedef	enum { BODY=3 } body_tag ;
#define def_BIND 4
typedef	enum { DEF=5 } def_tag ;
#define adt_BIND 6
typedef	enum { ADT=7 } adt_tag ;
#define sum_BIND 8
typedef	enum { SUM=9 } sum_tag ;
#define summand_BIND 10
typedef	enum { SUMMAND=11 } summand_tag ;
#define product_BIND 12
typedef	enum { PRODUCT=13 } product_tag ;
#define factor_BIND 14
typedef	enum { FACTOR=15 } factor_tag ;
#define ident_BIND 16
typedef	enum { IDENT=17 } ident_tag ;
#define nametablelength 18
extern char *nametable [] ;
extern void __adterr__( void *, int, int, char * ) ;
typedef	struct admin_struct {
	int tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
} admin ;

typedef	struct input_struct {
	input_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct input_struct **_binding ;
		struct {
			string _header ;
			struct body_struct *_body ;
			string _trailer ;
		} _INPUT ;
	} data ;
} input ;

typedef	struct body_struct {
	body_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct body_struct **_binding ;
		struct {
			struct def_struct *_def ;
			struct body_struct *_next ;
		} _BODY ;
	} data ;
} body ;

typedef	struct def_struct {
	def_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct def_struct **_binding ;
		struct {
			string _comment ;
			struct ident_struct *_ident ;
			struct product_struct *_product ;
			struct adt_struct *_adt ;
		} _DEF ;
	} data ;
} def ;

typedef	struct adt_struct {
	adt_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct adt_struct **_binding ;
		struct {
			struct sum_struct *_sum ;
			string _class ;
			struct product_struct *_parameters ;
		} _ADT ;
	} data ;
} adt ;

typedef	struct sum_struct {
	sum_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct sum_struct **_binding ;
		struct {
			struct summand_struct *_summand ;
			struct sum_struct *_next ;
		} _SUM ;
	} data ;
} sum ;

typedef	struct summand_struct {
	summand_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct summand_struct **_binding ;
		struct {
			string _comment ;
			struct ident_struct *_ident ;
			struct product_struct *_product ;
		} _SUMMAND ;
	} data ;
} summand ;

typedef	struct product_struct {
	product_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct product_struct **_binding ;
		struct {
			struct factor_struct *_factor ;
			struct product_struct *_next ;
		} _PRODUCT ;
	} data ;
} product ;

typedef	struct factor_struct {
	factor_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct factor_struct **_binding ;
		struct {
			string _comment ;
			int _visibility ;
			struct ident_struct *_type ;
			string _star ;
			struct ident_struct *_field ;
		} _FACTOR ;
	} data ;
} factor ;

typedef	struct ident_struct {
	ident_tag tag ;
	int flag ;
	int lineno ;
	int charno ;
	char *filename ;
	union {
		struct ident_struct **_binding ;
		struct {
			string _ident ;
		} _IDENT ;
	} data ;
} ident ;

#define nlinput ( ( input*) NULL )
input *bdinput( input **binding ) ;
bool mtinput( input *pattern, input *subject ) ;
void frinput( input **subject ) ;
void fdinput( input **subject ) ;
input *cpinput( input *subject ) ;
void mvinput( input *subject, input *object ) ;
void prinput( int indent, input *subject ) ;
void clinput( input *subject ) ;
#ifndef _FAST_
input_tag gtinputtag( input *subject ) ;
#else
#define gtinputtag( subject ) ( ( subject )->tag )
#endif
void stinputtag( input *subject, input_tag tag ) ;
#define gtinputfilename( subject ) ( ( subject )->filename )
#define gtinputlineno( subject ) ( ( subject )->lineno )
#define gtinputcharno( subject ) ( ( subject )->charno )
void lfinput( input *subject ) ;
input *mkINPUT( string _header, body *_body, string _trailer ) ;
input *ptINPUT( string _header, body *_body, string _trailer ) ;
string *adINPUTheader( input *subject ) ;
#ifndef _FAST_
string gtINPUTheader( input *subject ) ;
#else
#define gtINPUTheader( subject ) ( ( subject )->data._INPUT._header )
#endif
void stINPUTheader( input *subject, string value ) ;
body **adINPUTbody( input *subject ) ;
#ifndef _FAST_
body *gtINPUTbody( input *subject ) ;
#else
#define gtINPUTbody( subject ) ( ( subject )->data._INPUT._body )
#endif
void stINPUTbody( input *subject, body *value ) ;
string *adINPUTtrailer( input *subject ) ;
#ifndef _FAST_
string gtINPUTtrailer( input *subject ) ;
#else
#define gtINPUTtrailer( subject ) ( ( subject )->data._INPUT._trailer )
#endif
void stINPUTtrailer( input *subject, string value ) ;

#define nlbody ( ( body*) NULL )
body *bdbody( body **binding ) ;
bool mtbody( body *pattern, body *subject ) ;
void frbody( body **subject ) ;
void fdbody( body **subject ) ;
body *cpbody( body *subject ) ;
void mvbody( body *subject, body *object ) ;
void prbody( int indent, body *subject ) ;
void clbody( body *subject ) ;
#ifndef _FAST_
body_tag gtbodytag( body *subject ) ;
#else
#define gtbodytag( subject ) ( ( subject )->tag )
#endif
void stbodytag( body *subject, body_tag tag ) ;
#define gtbodyfilename( subject ) ( ( subject )->filename )
#define gtbodylineno( subject ) ( ( subject )->lineno )
#define gtbodycharno( subject ) ( ( subject )->charno )
void lfbody( body *subject ) ;
body *mkBODY( def *_def, body *_next ) ;
body *ptBODY( def *_def, body *_next ) ;
def **adBODYdef( body *subject ) ;
#ifndef _FAST_
def *gtBODYdef( body *subject ) ;
#else
#define gtBODYdef( subject ) ( ( subject )->data._BODY._def )
#endif
void stBODYdef( body *subject, def *value ) ;
body **adBODYnext( body *subject ) ;
#ifndef _FAST_
body *gtBODYnext( body *subject ) ;
#else
#define gtBODYnext( subject ) ( ( subject )->data._BODY._next )
#endif
void stBODYnext( body *subject, body *value ) ;
body *apbody( body *subject, body *object ) ;
void itbody( void ( *f ) ( void *, def * ), void *x, body *subject ) ;

#define nldef ( ( def*) NULL )
def *bddef( def **binding ) ;
bool mtdef( def *pattern, def *subject ) ;
void frdef( def **subject ) ;
void fddef( def **subject ) ;
def *cpdef( def *subject ) ;
void mvdef( def *subject, def *object ) ;
void prdef( int indent, def *subject ) ;
void cldef( def *subject ) ;
#ifndef _FAST_
def_tag gtdeftag( def *subject ) ;
#else
#define gtdeftag( subject ) ( ( subject )->tag )
#endif
void stdeftag( def *subject, def_tag tag ) ;
#define gtdeffilename( subject ) ( ( subject )->filename )
#define gtdeflineno( subject ) ( ( subject )->lineno )
#define gtdefcharno( subject ) ( ( subject )->charno )
void lfdef( def *subject ) ;
def *mkDEF( string _comment, ident *_ident, product *_product, adt *_adt ) ;
def *ptDEF( string _comment, ident *_ident, product *_product, adt *_adt ) ;
string *adDEFcomment( def *subject ) ;
#ifndef _FAST_
string gtDEFcomment( def *subject ) ;
#else
#define gtDEFcomment( subject ) ( ( subject )->data._DEF._comment )
#endif
void stDEFcomment( def *subject, string value ) ;
ident **adDEFident( def *subject ) ;
#ifndef _FAST_
ident *gtDEFident( def *subject ) ;
#else
#define gtDEFident( subject ) ( ( subject )->data._DEF._ident )
#endif
void stDEFident( def *subject, ident *value ) ;
product **adDEFproduct( def *subject ) ;
#ifndef _FAST_
product *gtDEFproduct( def *subject ) ;
#else
#define gtDEFproduct( subject ) ( ( subject )->data._DEF._product )
#endif
void stDEFproduct( def *subject, product *value ) ;
adt **adDEFadt( def *subject ) ;
#ifndef _FAST_
adt *gtDEFadt( def *subject ) ;
#else
#define gtDEFadt( subject ) ( ( subject )->data._DEF._adt )
#endif
void stDEFadt( def *subject, adt *value ) ;

#define nladt ( ( adt*) NULL )
adt *bdadt( adt **binding ) ;
bool mtadt( adt *pattern, adt *subject ) ;
void fradt( adt **subject ) ;
void fdadt( adt **subject ) ;
adt *cpadt( adt *subject ) ;
void mvadt( adt *subject, adt *object ) ;
void pradt( int indent, adt *subject ) ;
void cladt( adt *subject ) ;
#ifndef _FAST_
adt_tag gtadttag( adt *subject ) ;
#else
#define gtadttag( subject ) ( ( subject )->tag )
#endif
void stadttag( adt *subject, adt_tag tag ) ;
#define gtadtfilename( subject ) ( ( subject )->filename )
#define gtadtlineno( subject ) ( ( subject )->lineno )
#define gtadtcharno( subject ) ( ( subject )->charno )
void lfadt( adt *subject ) ;
adt *mkADT( sum *_sum, string _class, product *_parameters ) ;
adt *ptADT( sum *_sum, string _class, product *_parameters ) ;
sum **adADTsum( adt *subject ) ;
#ifndef _FAST_
sum *gtADTsum( adt *subject ) ;
#else
#define gtADTsum( subject ) ( ( subject )->data._ADT._sum )
#endif
void stADTsum( adt *subject, sum *value ) ;
string *adADTclass( adt *subject ) ;
#ifndef _FAST_
string gtADTclass( adt *subject ) ;
#else
#define gtADTclass( subject ) ( ( subject )->data._ADT._class )
#endif
void stADTclass( adt *subject, string value ) ;
product **adADTparameters( adt *subject ) ;
#ifndef _FAST_
product *gtADTparameters( adt *subject ) ;
#else
#define gtADTparameters( subject ) ( ( subject )->data._ADT._parameters )
#endif
void stADTparameters( adt *subject, product *value ) ;

#define nlsum ( ( sum*) NULL )
sum *bdsum( sum **binding ) ;
bool mtsum( sum *pattern, sum *subject ) ;
void frsum( sum **subject ) ;
void fdsum( sum **subject ) ;
sum *cpsum( sum *subject ) ;
void mvsum( sum *subject, sum *object ) ;
void prsum( int indent, sum *subject ) ;
void clsum( sum *subject ) ;
#ifndef _FAST_
sum_tag gtsumtag( sum *subject ) ;
#else
#define gtsumtag( subject ) ( ( subject )->tag )
#endif
void stsumtag( sum *subject, sum_tag tag ) ;
#define gtsumfilename( subject ) ( ( subject )->filename )
#define gtsumlineno( subject ) ( ( subject )->lineno )
#define gtsumcharno( subject ) ( ( subject )->charno )
void lfsum( sum *subject ) ;
sum *mkSUM( summand *_summand, sum *_next ) ;
sum *ptSUM( summand *_summand, sum *_next ) ;
summand **adSUMsummand( sum *subject ) ;
#ifndef _FAST_
summand *gtSUMsummand( sum *subject ) ;
#else
#define gtSUMsummand( subject ) ( ( subject )->data._SUM._summand )
#endif
void stSUMsummand( sum *subject, summand *value ) ;
sum **adSUMnext( sum *subject ) ;
#ifndef _FAST_
sum *gtSUMnext( sum *subject ) ;
#else
#define gtSUMnext( subject ) ( ( subject )->data._SUM._next )
#endif
void stSUMnext( sum *subject, sum *value ) ;
sum *apsum( sum *subject, sum *object ) ;
void itsum( void ( *f ) ( void *, summand * ), void *x, sum *subject ) ;

#define nlsummand ( ( summand*) NULL )
summand *bdsummand( summand **binding ) ;
bool mtsummand( summand *pattern, summand *subject ) ;
void frsummand( summand **subject ) ;
void fdsummand( summand **subject ) ;
summand *cpsummand( summand *subject ) ;
void mvsummand( summand *subject, summand *object ) ;
void prsummand( int indent, summand *subject ) ;
void clsummand( summand *subject ) ;
#ifndef _FAST_
summand_tag gtsummandtag( summand *subject ) ;
#else
#define gtsummandtag( subject ) ( ( subject )->tag )
#endif
void stsummandtag( summand *subject, summand_tag tag ) ;
#define gtsummandfilename( subject ) ( ( subject )->filename )
#define gtsummandlineno( subject ) ( ( subject )->lineno )
#define gtsummandcharno( subject ) ( ( subject )->charno )
void lfsummand( summand *subject ) ;
summand *mkSUMMAND( string _comment, ident *_ident, product *_product ) ;
summand *ptSUMMAND( string _comment, ident *_ident, product *_product ) ;
string *adSUMMANDcomment( summand *subject ) ;
#ifndef _FAST_
string gtSUMMANDcomment( summand *subject ) ;
#else
#define gtSUMMANDcomment( subject ) ( ( subject )->data._SUMMAND._comment )
#endif
void stSUMMANDcomment( summand *subject, string value ) ;
ident **adSUMMANDident( summand *subject ) ;
#ifndef _FAST_
ident *gtSUMMANDident( summand *subject ) ;
#else
#define gtSUMMANDident( subject ) ( ( subject )->data._SUMMAND._ident )
#endif
void stSUMMANDident( summand *subject, ident *value ) ;
product **adSUMMANDproduct( summand *subject ) ;
#ifndef _FAST_
product *gtSUMMANDproduct( summand *subject ) ;
#else
#define gtSUMMANDproduct( subject ) ( ( subject )->data._SUMMAND._product )
#endif
void stSUMMANDproduct( summand *subject, product *value ) ;

#define nlproduct ( ( product*) NULL )
product *bdproduct( product **binding ) ;
bool mtproduct( product *pattern, product *subject ) ;
void frproduct( product **subject ) ;
void fdproduct( product **subject ) ;
product *cpproduct( product *subject ) ;
void mvproduct( product *subject, product *object ) ;
void prproduct( int indent, product *subject ) ;
void clproduct( product *subject ) ;
#ifndef _FAST_
product_tag gtproducttag( product *subject ) ;
#else
#define gtproducttag( subject ) ( ( subject )->tag )
#endif
void stproducttag( product *subject, product_tag tag ) ;
#define gtproductfilename( subject ) ( ( subject )->filename )
#define gtproductlineno( subject ) ( ( subject )->lineno )
#define gtproductcharno( subject ) ( ( subject )->charno )
void lfproduct( product *subject ) ;
product *mkPRODUCT( factor *_factor, product *_next ) ;
product *ptPRODUCT( factor *_factor, product *_next ) ;
factor **adPRODUCTfactor( product *subject ) ;
#ifndef _FAST_
factor *gtPRODUCTfactor( product *subject ) ;
#else
#define gtPRODUCTfactor( subject ) ( ( subject )->data._PRODUCT._factor )
#endif
void stPRODUCTfactor( product *subject, factor *value ) ;
product **adPRODUCTnext( product *subject ) ;
#ifndef _FAST_
product *gtPRODUCTnext( product *subject ) ;
#else
#define gtPRODUCTnext( subject ) ( ( subject )->data._PRODUCT._next )
#endif
void stPRODUCTnext( product *subject, product *value ) ;
product *approduct( product *subject, product *object ) ;
void itproduct( void ( *f ) ( void *, factor * ), void *x, product *subject ) ;

#define nlfactor ( ( factor*) NULL )
factor *bdfactor( factor **binding ) ;
bool mtfactor( factor *pattern, factor *subject ) ;
void frfactor( factor **subject ) ;
void fdfactor( factor **subject ) ;
factor *cpfactor( factor *subject ) ;
void mvfactor( factor *subject, factor *object ) ;
void prfactor( int indent, factor *subject ) ;
void clfactor( factor *subject ) ;
#ifndef _FAST_
factor_tag gtfactortag( factor *subject ) ;
#else
#define gtfactortag( subject ) ( ( subject )->tag )
#endif
void stfactortag( factor *subject, factor_tag tag ) ;
#define gtfactorfilename( subject ) ( ( subject )->filename )
#define gtfactorlineno( subject ) ( ( subject )->lineno )
#define gtfactorcharno( subject ) ( ( subject )->charno )
void lffactor( factor *subject ) ;
factor *mkFACTOR( string _comment, int _visibility, ident *_type, string _star, ident *_field ) ;
factor *ptFACTOR( string _comment, int _visibility, ident *_type, string _star, ident *_field ) ;
string *adFACTORcomment( factor *subject ) ;
#ifndef _FAST_
string gtFACTORcomment( factor *subject ) ;
#else
#define gtFACTORcomment( subject ) ( ( subject )->data._FACTOR._comment )
#endif
void stFACTORcomment( factor *subject, string value ) ;
int *adFACTORvisibility( factor *subject ) ;
#ifndef _FAST_
int gtFACTORvisibility( factor *subject ) ;
#else
#define gtFACTORvisibility( subject ) ( ( subject )->data._FACTOR._visibility )
#endif
void stFACTORvisibility( factor *subject, int value ) ;
ident **adFACTORtype( factor *subject ) ;
#ifndef _FAST_
ident *gtFACTORtype( factor *subject ) ;
#else
#define gtFACTORtype( subject ) ( ( subject )->data._FACTOR._type )
#endif
void stFACTORtype( factor *subject, ident *value ) ;
string *adFACTORstar( factor *subject ) ;
#ifndef _FAST_
string gtFACTORstar( factor *subject ) ;
#else
#define gtFACTORstar( subject ) ( ( subject )->data._FACTOR._star )
#endif
void stFACTORstar( factor *subject, string value ) ;
ident **adFACTORfield( factor *subject ) ;
#ifndef _FAST_
ident *gtFACTORfield( factor *subject ) ;
#else
#define gtFACTORfield( subject ) ( ( subject )->data._FACTOR._field )
#endif
void stFACTORfield( factor *subject, ident *value ) ;

#define nlident ( ( ident*) NULL )
ident *bdident( ident **binding ) ;
bool mtident( ident *pattern, ident *subject ) ;
void frident( ident **subject ) ;
void fdident( ident **subject ) ;
ident *cpident( ident *subject ) ;
void mvident( ident *subject, ident *object ) ;
void prident( int indent, ident *subject ) ;
void clident( ident *subject ) ;
#ifndef _FAST_
ident_tag gtidenttag( ident *subject ) ;
#else
#define gtidenttag( subject ) ( ( subject )->tag )
#endif
void stidenttag( ident *subject, ident_tag tag ) ;
#define gtidentfilename( subject ) ( ( subject )->filename )
#define gtidentlineno( subject ) ( ( subject )->lineno )
#define gtidentcharno( subject ) ( ( subject )->charno )
void lfident( ident *subject ) ;
ident *mkIDENT( string _ident ) ;
ident *ptIDENT( string _ident ) ;
string *adIDENTident( ident *subject ) ;
#ifndef _FAST_
string gtIDENTident( ident *subject ) ;
#else
#define gtIDENTident( subject ) ( ( subject )->data._IDENT._ident )
#endif
void stIDENTident( ident *subject, string value ) ;

#define csINPUT( _input_, header, body, trailer ) \
	case INPUT : \
		header = _input_->data._INPUT._header ; \
		body = _input_->data._INPUT._body ; \
		trailer = _input_->data._INPUT._trailer ;
#define csBODY( _body_, def, next ) \
	case BODY : \
		def = _body_->data._BODY._def ; \
		next = _body_->data._BODY._next ;
#define csDEF( _def_, comment, ident, product, adt ) \
	case DEF : \
		comment = _def_->data._DEF._comment ; \
		ident = _def_->data._DEF._ident ; \
		product = _def_->data._DEF._product ; \
		adt = _def_->data._DEF._adt ;
#define csADT( _adt_, sum, class, parameters ) \
	case ADT : \
		sum = _adt_->data._ADT._sum ; \
		class = _adt_->data._ADT._class ; \
		parameters = _adt_->data._ADT._parameters ;
#define csSUM( _sum_, summand, next ) \
	case SUM : \
		summand = _sum_->data._SUM._summand ; \
		next = _sum_->data._SUM._next ;
#define csSUMMAND( _summand_, comment, ident, product ) \
	case SUMMAND : \
		comment = _summand_->data._SUMMAND._comment ; \
		ident = _summand_->data._SUMMAND._ident ; \
		product = _summand_->data._SUMMAND._product ;
#define csPRODUCT( _product_, factor, next ) \
	case PRODUCT : \
		factor = _product_->data._PRODUCT._factor ; \
		next = _product_->data._PRODUCT._next ;
#define csFACTOR( _factor_, comment, visibility, type, star, field ) \
	case FACTOR : \
		comment = _factor_->data._FACTOR._comment ; \
		visibility = _factor_->data._FACTOR._visibility ; \
		type = _factor_->data._FACTOR._type ; \
		star = _factor_->data._FACTOR._star ; \
		field = _factor_->data._FACTOR._field ;
#define csIDENT( _ident_, ident ) \
	case IDENT : \
		ident = _ident_->data._IDENT._ident ;
#define ininput( binding ) { \
	.tag = input_BIND, \
	.data._binding = binding \
}
#define inINPUT( header, body, trailer ) { \
	.tag = INPUT, \
	.data._INPUT._header = (string)header, \
	.data._INPUT._body = body, \
	.data._INPUT._trailer = (string)trailer \
}
#define inbody( binding ) { \
	.tag = body_BIND, \
	.data._binding = binding \
}
#define inBODY( def, next ) { \
	.tag = BODY, \
	.data._BODY._def = def, \
	.data._BODY._next = next \
}
#define indef( binding ) { \
	.tag = def_BIND, \
	.data._binding = binding \
}
#define inDEF( comment, ident, product, adt ) { \
	.tag = DEF, \
	.data._DEF._comment = (string)comment, \
	.data._DEF._ident = ident, \
	.data._DEF._product = product, \
	.data._DEF._adt = adt \
}
#define inadt( binding ) { \
	.tag = adt_BIND, \
	.data._binding = binding \
}
#define inADT( sum, class, parameters ) { \
	.tag = ADT, \
	.data._ADT._sum = sum, \
	.data._ADT._class = (string)class, \
	.data._ADT._parameters = parameters \
}
#define insum( binding ) { \
	.tag = sum_BIND, \
	.data._binding = binding \
}
#define inSUM( summand, next ) { \
	.tag = SUM, \
	.data._SUM._summand = summand, \
	.data._SUM._next = next \
}
#define insummand( binding ) { \
	.tag = summand_BIND, \
	.data._binding = binding \
}
#define inSUMMAND( comment, ident, product ) { \
	.tag = SUMMAND, \
	.data._SUMMAND._comment = (string)comment, \
	.data._SUMMAND._ident = ident, \
	.data._SUMMAND._product = product \
}
#define inproduct( binding ) { \
	.tag = product_BIND, \
	.data._binding = binding \
}
#define inPRODUCT( factor, next ) { \
	.tag = PRODUCT, \
	.data._PRODUCT._factor = factor, \
	.data._PRODUCT._next = next \
}
#define infactor( binding ) { \
	.tag = factor_BIND, \
	.data._binding = binding \
}
#define inFACTOR( comment, visibility, type, star, field ) { \
	.tag = FACTOR, \
	.data._FACTOR._comment = (string)comment, \
	.data._FACTOR._visibility = (int)visibility, \
	.data._FACTOR._type = type, \
	.data._FACTOR._star = (string)star, \
	.data._FACTOR._field = field \
}
#define inident( binding ) { \
	.tag = ident_BIND, \
	.data._binding = binding \
}
#define inIDENT( ident ) { \
	.tag = IDENT, \
	.data._IDENT._ident = (string)ident \
}

#endif
