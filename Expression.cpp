#include "Expression.h"

Expression::Expression()
: ASTNode()
{
}

Expression::Expression(Scope* context)
: ASTNode(context)
{
}
