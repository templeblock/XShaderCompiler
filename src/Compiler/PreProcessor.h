/*
 * PreProcessor.h
 * 
 * This file is part of the XShaderCompiler project (Copyright (c) 2014-2016 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef XSC_PRE_PROCESSOR_H
#define XSC_PRE_PROCESSOR_H


#include <Xsc/Xsc.h>
#include <Xsc/Log.h>
#include "PreProcessorScanner.h"
#include "TokenString.h"
#include "ASTEnums.h"
#include "Parser.h"
#include "SourceCode.h"
#include <iostream>
#include <functional>
#include <initializer_list>
#include <stack>
#include <map>
#include <set>


namespace Xsc
{


/*
Pre-processor to substitute macros and include directives.
The preprocessor works on something similar to a Concrete Syntax Tree (CST) rather than an Abstract Syntax Tree (AST).
This is because the output is not an intermediate representation but rather concrete source code.
Therefore, all white spaces and new-line characters must NOT be ignored.
All other parsers and analyzers only work on an AST.
*/
class PreProcessor : public Parser
{
    
    public:
        
        PreProcessor(IncludeHandler& includeHandler, Log* log = nullptr);

        std::shared_ptr<std::iostream> Process(const SourceCodePtr& input, const std::string& filename = "");

    private:
        
        /* === Structures === */

        struct Macro
        {
            std::vector<std::string>    parameters;
            TokenPtrString              tokenString;
        };

        struct IfBlock
        {
            TokenPtr        directiveToken;
            SourceCodePtr   directiveSource;
            bool            active         = true;
            bool            expectEndif    = false;
        };

        using MacroPtr      = std::shared_ptr<Macro>;
        using BinaryOpList  = std::initializer_list<BinaryOp>;

        /* === Functions === */

        ScannerPtr MakeScanner() override;

        // Returns true if the specified symbol is defined.
        bool IsDefined(const std::string& ident) const;

        void PushIfBlock(const TokenPtr& directiveToken, bool active = false, bool expectEndif = false);
        void PopIfBlock();

        // Returns the if-block state from the top of the stack. If the stack is empty, the default state is returned.
        IfBlock TopIfBlock() const;

        /*
        Replaces all identifiers (specified by 'macro.parameters') in the token string (specified by 'macro.tokenString')
        by the respective replacement (specified by 'arguments'). The number of identifiers and the number of replacements must be equal.
        */
        TokenPtrString ExpandMacro(const Macro& macro, const std::vector<TokenPtrString>& arguments);

        // Builds a left-to-right binary-expression tree hierarchy for the specified list of expressions.
        ExprPtr BuildBinaryExprTree(std::vector<ExprPtr>& exprs, std::vector<BinaryOp>& ops);

        /* === Parse functions === */

        void ParseProgram();

        void ParesComment();
        void ParseIdent();
        TokenPtrString ParseIdentAsTokenString();
        TokenPtrString ParseIdentArgumentsForMacro(const TokenPtr& identToken, const Macro& macro);
        void ParseMisc();
        
        void ParseDirective();
        void ParseAnyIfDirectiveAndSkipValidation();
        void ParseDirectiveDefine();
        void ParseDirectiveUndef();
        void ParseDirectiveInclude();
        void ParseDirectiveIf(bool skipEvaluation = false);
        void ParseDirectiveIfdef(bool skipEvaluation = false);
        void ParseDirectiveIfndef(bool skipEvaluation = false);
        void ParseDirectiveElif(bool skipEvaluation = false);
        void ParseDirectiveIfOrElifCondition(bool skipEvaluation = false);
        void ParseDirectiveElse();
        void ParseDirectiveEndif();
        void ParseDirectivePragma();
        void ParseDirectiveLine();
        void ParseDirectiveError();

        ExprPtr ParseExpr();
        
        ExprPtr ParseAbstractBinaryExpr(
            const std::function<ExprPtr()>& parseFunc,
            const BinaryOpList& binaryOps
        );

        ExprPtr ParseLogicOrExpr();
        ExprPtr ParseLogicAndExpr();
        ExprPtr ParseBitwiseOrExpr();
        ExprPtr ParseBitwiseXOrExpr();
        ExprPtr ParseBitwiseAndExpr();
        ExprPtr ParseEqualityExpr();
        ExprPtr ParseRelationExpr();
        ExprPtr ParseShiftExpr();
        ExprPtr ParseAddExpr();
        ExprPtr ParseSubExpr();
        ExprPtr ParseMulExpr();
        ExprPtr ParseDivExpr();
        ExprPtr ParseValueExpr();

        TokenPtrString ParseDirectiveTokenString(bool expandDefinedDirective = false);
        TokenPtrString ParseArgumentTokenString();

        /* === Members === */

        IncludeHandler&                     includeHandler_;

        std::shared_ptr<std::stringstream>  output_;

        std::map<std::string, MacroPtr>     macros_;
        std::set<std::string>               onceIncluded_;

        /*
        Stack to store the info which if-block in the hierarchy is active.
        Once an if-block is inactive, all subsequent if-blocks are inactive, too.
        */
        std::stack<IfBlock>                 ifBlockStack_;

};


} // /namespace Xsc


#endif



// ================================================================================