import{_ as n,c as s,o as a,d as p}from"./app.2ed2a9a6.js";const m='{"title":"Add","description":"","frontmatter":{},"headers":[],"relativePath":"introduction/operators/add.md","lastUpdated":1651606220000}',e={},t=p(`<h1 id="add" tabindex="-1">Add <a class="header-anchor" href="#add" aria-hidden="true">#</a></h1><p>A scalar (a in the example) will be promoted to a 2d vector:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> a <span class="token operator">=</span> <span class="token number">7.0</span>
vecmath<span class="token operator">&gt;</span> b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> c <span class="token operator">=</span> a <span class="token operator">+</span> b
vecmath<span class="token operator">&gt;</span> printAll
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br><span class="line-number">4</span><br></div></div><p>The result is :</p><div class="language-cpp line-numbers-mode"><pre><code>a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">7</span><span class="token punctuation">]</span>
b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
c <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">10.1</span><span class="token punctuation">,</span><span class="token number">11.1</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>Adding a 2d vector to a 3d vector leads to a different type of promotion of the 2d vector:</p><div class="language-cpp line-numbers-mode"><pre><code>vecmath<span class="token operator">&gt;</span> a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">4.2</span><span class="token punctuation">,</span><span class="token number">8.3</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">5</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
vecmath<span class="token operator">&gt;</span> c <span class="token operator">=</span> a <span class="token operator">+</span> b
vecmath<span class="token operator">&gt;</span> printAll
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br><span class="line-number">4</span><br></div></div><p>The result is :</p><div class="language-cpp line-numbers-mode"><pre><code>a <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">4.2</span><span class="token punctuation">,</span><span class="token number">8.3</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">5</span><span class="token punctuation">]</span>
b <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">3.1</span><span class="token punctuation">,</span><span class="token number">4.1</span><span class="token punctuation">]</span>
c <span class="token operator">=</span> <span class="token punctuation">[</span><span class="token number">7.3</span><span class="token punctuation">,</span><span class="token number">12.4</span><span class="token punctuation">,</span><span class="token operator">-</span><span class="token number">5</span><span class="token punctuation">]</span>
</code></pre><div class="line-numbers-wrapper"><span class="line-number">1</span><br><span class="line-number">2</span><br><span class="line-number">3</span><br></div></div><p>It is possible to use a quaternion to a 1d,2d or 3d vector but this has no special meaning so it is not discussed here.</p>`,10),o=[t];function c(r,l,u,i,k,d){return a(),s("div",null,o)}var v=n(e,[["render",c]]);export{m as __pageData,v as default};
