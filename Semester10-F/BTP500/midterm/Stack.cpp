 
 / /   S t a c k . c p p   :   T h i s   f i l e   c o n t a i n s   t h e   ' m a i n '   f u n c t i o n .   P r o g r a m   e x e c u t i o n   b e g i n s   a n d   e n d s   t h e r e .  
 / /  
  
 # i n c l u d e   " s t a c k . h "  
 # i n c l u d e   < i o s t r e a m >  
  
 i n t   m a i n ( )  
 {  
 	 L S t a c k < i n t >   l i s t O f I n t s ;  
  
         / / A d d   t e n   i n t e g e r s  
 	 f o r   ( i n t   i   =   1 ;   i   < =   1 0 ;   + + i )   {  
 	 	 l i s t O f I n t s . p u s h ( i ) ;  
 	 }  
 	 i f   ( l i s t O f I n t s . i s E m p t y ( ) )   s t d : : c o u t   < <   " T h e   l i s t   i s   e m p t y . "   < <   s t d : : e n d l ;  
 	 e l s e   s t d : : c o u t   < <   " T h e   l i s t   i s   n o t   e m p t y . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T o p   o f   t h e   s t a c k   i s   "   < <   l i s t O f I n t s . t o p ( )   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T h e   e n t i r e   s t a c k   i s   " ;  
 	 l i s t O f I n t s . p r i n t ( ) ;  
  
 	 / / R e m o v e   f i v e   i n t e g e r s  
 	 f o r   ( i n t   i   =   0 ;   i   <   5 ;   + + i )   {  
 	 	 l i s t O f I n t s . p o p ( ) ;  
 	 }  
  
 	 i f   ( l i s t O f I n t s . i s E m p t y ( ) )   s t d : : c o u t   < <   " T h e   l i s t   i s   e m p t y . "   < <   s t d : : e n d l ;  
 	 e l s e   s t d : : c o u t   < <   " T h e   l i s t   i s   n o t   e m p t y . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T o p   o f   t h e   s t a c k   i s   "   < <   l i s t O f I n t s . t o p ( )   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T h e   e n t i r e   s t a c k   i s   " ;  
 	 l i s t O f I n t s . p r i n t ( ) ;  
  
 	 / / R e m o v e   a n o t h e r   f i v e   i n t e g e r s  
 	 f o r   ( i n t   i   =   0 ;   i   <   5 ;   + + i )   {  
 	 	 l i s t O f I n t s . p o p ( ) ;  
 	 }  
  
 	 i f   ( l i s t O f I n t s . i s E m p t y ( ) )   s t d : : c o u t   < <   " T h e   l i s t   i s   e m p t y . "   < <   s t d : : e n d l ;  
 	 e l s e   s t d : : c o u t   < <   " T h e   l i s t   i s   n o t   e m p t y . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T o p   o f   t h e   s t a c k   i s   "   < <   l i s t O f I n t s . t o p ( )   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " T h e   e n t i r e   s t a c k   i s   " ;  
 	 l i s t O f I n t s . p r i n t ( ) ;  
  
 	 r e t u r n   0 ;  
 }  
 