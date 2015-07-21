#pragma once

#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Basic/SourceManager.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Casting.h"

#include <string>
#include <sstream>

using namespace llvm;
using namespace clang;

class DeclVisitor : public clang::RecursiveASTVisitor<DeclVisitor> {
  clang::SourceManager &SourceManager;

public:
  DeclVisitor(clang::SourceManager &SourceManager)
      : SourceManager(SourceManager) {}

//  bool VisitDecl(clang::Decl *myDecl) {
//    llvm::outs() << "Found Decl "<<myDecl->getDeclKindName()<<" at " 
//      << getDeclLocation(myDecl->getLocStart()) << "\n";
//    if ( llvm::isa<clang::NamedDecl>(myDecl) ) {
//      llvm::outs() <<" got a named decl \n";
//   //   clang::NamedDecl *nD = llvm::cast<clang::NamedDecl>(myDecl);
//   //   VisitNamedDecl(nD);
//    }
//    return true;
//  }

  bool VisitNamedDecl(clang::NamedDecl *NamedDecl) {
    llvm::outs() << "-> Named : Found "<<NamedDecl->getDeclKindName() << ":"
                 << NamedDecl->getQualifiedNameAsString() << " at "
                 << getDeclLocation(NamedDecl->getLocStart()) << "\n";


    if( isa<VarDecl>(NamedDecl)) {
      outs() << "Got vardecl\n";
      VarDecl *vD = cast<VarDecl>(NamedDecl);
      VarDecl *defVarDecl = vD->getDefinition();
    llvm::outs() << "-> Definition - : Found "<<defVarDecl->getDeclKindName() << ":"
                 << defVarDecl->getQualifiedNameAsString() << " at "
                 << getDeclLocation(defVarDecl->getLocStart()) << "\n";


    }
   // llvm::outs() << "Dump begin\n";

   // NamedDecl->dump();
   // llvm::outs() << "================\n";
    return true;
  }

//  bool VisitStmt(Stmt *s) {
//    outs() << "Found stmt " << s->getStmtClassName() << " at " <<
//       getDeclLocation(s->getLocStart() )<< "\n";
//    return true;
//  }
//
//  bool VisitTypeLoc(TypeLoc t) {
//    outs() << "Found type " << t.getTypePtr()->getTypeClassName() << " at " <<
//       getDeclLocation(t.getLocStart() )<< "\n";
//    return true;
//  }
      

private:
  std::string getDeclLocation(clang::SourceLocation Loc) const {
    std::ostringstream OSS;
    OSS << SourceManager.getFilename(Loc).str() << ":"
        << SourceManager.getSpellingLineNumber(Loc) << ":"
        << SourceManager.getSpellingColumnNumber(Loc);
    return OSS.str();
  }
};
