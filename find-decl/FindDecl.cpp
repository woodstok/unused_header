#include "DeclFindingAction.h"

#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"

static llvm::cl::extrahelp
    CommonHelp(clang::tooling::CommonOptionsParser::HelpMessage);
llvm::cl::OptionCategory FindDeclCategory("find-decl options");

#define FIND_DECL_VERSION "0.0.1"

static void PrintVersion() {
  llvm::outs() << "find-decl version: " << FIND_DECL_VERSION << "\n";
}

static char FindDeclUsage[] = "find-decl <source file>";
  typedef std::vector<std::string>::const_iterator vs_ci;

int main(int argc, const char **argv) {
  llvm::cl::SetVersionPrinter(PrintVersion);
  clang::tooling::CommonOptionsParser option(argc, argv, FindDeclCategory,
                                             FindDeclUsage);

  auto files = option.getSourcePathList();
  vs_ci it = files.begin();
  llvm::outs() << "Dumping sourcepath list : ";

  while(it != files.end()) {

    llvm::outs() << *it << " ";
    it++;
  }
  llvm::outs() << "\n";
  clang::tooling::ClangTool tool(option.getCompilations(), files);

  return tool.run(clang::tooling::newFrontendActionFactory<DeclFindingAction>().get());
}

